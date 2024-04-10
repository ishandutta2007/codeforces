#include <bits/stdc++.h>
using namespace std;
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, (a))
#define rep1(i, a) iter(i, 1, (a)+1)
int bcj[105];
int g(int i){
    if(bcj[i])return bcj[i]=g(bcj[i]);
    return i;
}
int x[105],y[105];
int main() {
    ios_base::sync_with_stdio(false); 
	cin.tie(0);
	int n;cin>>n;
    rep(i,n)cin>>x[i]>>y[i];
    int ltk=n;
    rep(i,n)rep(j,n)if((x[i]==x[j])||(y[i]==y[j])){
        if(g(i)!=g(j)){
            bcj[g(i)]=g(j);
            ltk--;
        }
    }
    cout<<ltk-1<<endl;
    return 0;
}