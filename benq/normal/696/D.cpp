#include <bits/stdc++.h>

using namespace std; 

#define F0R(i,a) for (int i = 0; i < a; ++i)

typedef long long ll;

int n;
ll l;

struct mat {
	ll d[201][201];
	mat() {
		F0R(i,201) F0R(j,201) d[i][j] = -1;
		F0R(i,201) d[i][i] = 0;
	}
	mat operator*(const mat& B) {
		mat C;
		F0R(i,201) F0R(j,201) F0R(k,201) 
			if (d[i][k] != -1 && B.d[k][j] != -1) 
				C.d[i][j] = max(C.d[i][j],d[i][k]+B.d[k][j]);
		return C;
	}
};

mat po(mat b, ll p) {
	mat ans;
	while (p) {
		if (p&1) ans = ans*b;
		b = b*b;
		p /= 2;
	}
	return ans;
}

string arr[200];
int val[200], states = 1;
mat ori;

const int MAXS = 201;
const int MAXC = 26;
 
int out[MAXS], f[MAXS], g[MAXS][MAXC];

int buildMatchingMachine() {
    memset(out, 0, sizeof out);
    memset(g, -1, sizeof g);
 	
    F0R(i,n) {
        const string &word = arr[i];
        int currentState = 0;
 
        // Insert all characters of current word in arr[]
        F0R(j,word.size()) {
            int ch = word[j] - 'a';
 
            // Allocate a new node (create a new state) if a
            // node for ch doesn't exist.
            if (g[currentState][ch] == -1)
                g[currentState][ch] = states++;
 
            currentState = g[currentState][ch];
        }
 
        // Add current word in output function
        out[currentState] += val[i];
    }
 
    // For all characters which don't have an edge from
    // root (or state 0) in Trie, add a goto edge to state
    // 0 itself
    F0R(ch,MAXC)
        if (g[0][ch] == -1)
            g[0][ch] = 0;
 
    // Now, let's build the failure function
 
    // Initialize values in fail function
    memset(f, -1, sizeof f);
 
    // Failure function is computed in breadth first order
    // using a queue
    queue<int> q;
 
     // Iterate over every possible input
    F0R(ch,MAXC) {
        // All nodes of depth 1 have failure function value
        // as 0. For example, in above diagram we move to 0
        // from states 1 and 3.
        if (g[0][ch] != 0) {
            f[g[0][ch]] = 0;
            q.push(g[0][ch]);
        }
    }
 
    // Now queue has states 1 and 3
    while (q.size()) {
        // Remove the front state from queue
        int state = q.front();
        q.pop();
 
        // For the removed state, find failure function for
        // all those characters for which goto function is
        // not defined.
        F0R(ch,MAXC) {
            // If goto function is defined for character 'ch'
            // and 'state'
            if (g[state][ch] != -1) {
                // Find failure state of removed state
                int failure = f[state];
 
                // Find the deepest node labeled by proper
                // suffix of string from root to current
                // state.
                while (g[failure][ch] == -1)
                      failure = f[failure];
 
                failure = g[failure][ch];
                f[g[state][ch]] = failure;
 
                // Merge output values
                out[g[state][ch]] += out[failure];
 
                // Insert the next level node (of Trie) in Queue
                q.push(g[state][ch]);
            }
        }
    }
 
    return states;
}
 
int findNextState(int currentState, char nextInput) {
    int answer = currentState;
    int ch = nextInput - 'a';

    while (g[answer][ch] == -1) answer = f[answer];
    return g[answer][ch];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> l;
	F0R(i,n) cin >> val[i];
	F0R(i,n) cin >> arr[i];
	
    buildMatchingMachine();
    
	F0R(i,states) F0R(j,26) {
		int k = findNextState(i,'a'+j);
		ori.d[i][k] = out[k];
	}
	
	ori = po(ori,l);
	ll ans = 0;
	F0R(i,201) ans = max(ans,ori.d[0][i]);
	cout << ans;
}