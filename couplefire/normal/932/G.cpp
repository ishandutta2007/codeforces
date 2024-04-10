#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
using namespace std;
const int MAXN=1000005;
string s;
struct PalindromicTree{
    int N,cur;
    vector<map<int,int>> next;
    vector<int> link,start,len,diff,slink;
    PalindromicTree(): N(0),cur(0){
        node();
        len[0]=-1;
        node();
    }
    int node(){
        next.emplace_back();
        link.emplace_back(0);
        start.emplace_back(0);
        len.emplace_back(0);
        diff.emplace_back(0);
        slink.emplace_back(0);
        return N++;
    }
    void add_letter(int idx){
        while(true){
            if(idx-len[cur]-1>=0 && s[idx-len[cur]-1]==s[idx])
                break;
            cur=link[cur];
        }
        if(next[cur].find(s[idx])!=next[cur].end()){
            cur=next[cur][s[idx]];
            return;
        }
        node();
        next[cur][s[idx]]=N-1;
        len[N-1]=len[cur]+2;
        start[N-1]=idx-len[N-1]+1;
        if(len[N-1]==1){
            link[N-1]=diff[N-1]=slink[N-1]=1;
            cur=N-1;
            return;
        }
        while(true){
            cur=link[cur];
            if(idx-len[cur]-1>=0 && s[idx-len[cur]-1]==s[idx])
                break;
        }
        link[N-1]=next[cur][s[idx]];
        diff[N-1]=len[N-1]-len[link[N-1]];
        if(diff[N-1]==diff[link[N-1]])
        	slink[N-1]=slink[link[N-1]];
        else
        	slink[N-1]=link[N-1];
        cur=N-1;
    }
};
ll dp[MAXN],sans[MAXN];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	PalindromicTree pt;
	int i,cur;
	string str;
	cin>>str;
	for(i=0;i<sz(str)/2;i++){
		s.pb(str[i]);
		s.pb(str[sz(str)-i-1]);
	}
	dp[0]=1;
	for(i=1;i<=sz(s);i++){
		pt.add_letter(i-1);
		for(cur=pt.cur;cur>1;cur=pt.slink[cur]){
			sans[cur]=dp[i-pt.len[pt.slink[cur]]-pt.diff[cur]];
			if(pt.diff[cur]==pt.diff[pt.link[cur]])
				sans[cur]=(sans[cur]+sans[pt.link[cur]])%hell;
			dp[i]=(dp[i]+sans[cur])%hell;
		}
		if(i&1)
			dp[i]=0;
	}
	cout<<dp[sz(s)];
	return 0;
}