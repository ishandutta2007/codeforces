// optimized version of code of tap_tapii
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define int long long
#define f first
#define vc vector
#define s second

using namespace std;
vector <int> unten;
vector <int> parent;
int n, m;
int f_par(int wer){
	return parent[wer]<0?wer:parent[wer] = f_par(parent[wer]);
}
void uni (int a, int b){
 //   cout << "uni" <<  a << " " << b << endl;
	a=f_par(a); b=f_par(b);
	if(a!=b){
		if(parent[a]>parent[b]) swap(a, b);
		parent[a]+=parent[b];
		parent[b] = a;
	}
}
int rev_numb(int wer){
	return wer ^ ((1<<n)-1);
}

void do_par(int wer){
  //  cout << "wer in do_par: " <<wer  << endl;
    static queue<int> q;
	q.emplace(wer);
	unten[wer]=2;
	while(!q.empty()){
		wer = q.front(); q.pop();
		for (int i=0; i<n; i++){
			if (((wer & (1<<i)) == 0) && unten[wer+(1<<i)]>0){
				uni(wer, wer+(1<<i));
				if (unten[wer+(1<<i)]==1){
					q.emplace(wer+(1<<i));
					unten[wer+(1<<i)] = 2;
				}
			}
		}
	}
}
bool find_sub( int wer){
   // cout <<"find " <<wer << endl;
   // if (wer==26){cout << "tried here" << endl;}
    if (unten[wer]!=-1) return unten[wer];
    //if (hat.find(wer)!=hat.end()) return unten[wer]=1;
    int hat=0;
    for (int i=0; i<n; i++){
        if ((wer & (1<<i)) == 0){

            int next=wer+(1<<i);
           // if (wer==26){cout << next<< endl;}
            if (find_sub(next)) hat=1;
        }
    }
    return unten[wer]=hat;
}
void real_prob(int wer){
    int rev=rev_numb(wer);
    //cout << "unten" << unten[rev] <<"von: " << rev << endl;
    if (unten[rev]>0){
        do_par(rev);
    }
    //cout << "ref: " << rev << " wer: " << wer <<endl;
    uni(rev, wer);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef LOCAL_RUN
    freopen("input.txt", "r", stdin);
    int ttt;
    cin >> ttt;
    while(ttt--){
    #endif // LOCAL_RUN
    cin >> n >> m;
    vector <int> a (m);
    unten=vector <int> (1<<n, -1);
    parent =vector <int> (1<<n, -1);
    //for (int i=0; i<(1<<n); i++){
    //    parent[i]=i;
    //}
    for (int i=0; i<m; i++){
        cin >> a[i];
        a[i]=rev_numb(a[i]);
        unten[a[i]]=1;
    }
    for (int i=0; i<(1<<n); i++){
        if (unten[i]==-1) find_sub(i);
    }

    for (int i=0; i<m; i++){
        real_prob(a[i]);
    }
	
    set <int> dif_par;
    for (int i=0; i<m; i++){
        int p=f_par(a[i]);
        if (dif_par.find(p)==dif_par.end()){
            dif_par.insert(p);
        }
    }

    cout << dif_par.size() << "\n";

    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
}