#include <bits/stdc++.h>
using namespace std;
#define pb push_back
map<int,int> z;
int main(){
    ios_base::sync_with_stdio(false);
    int n,m,d,x=0,y=10005,t;
    cin>>n>>m>>d;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>t;
            if(t>x)x=t;
            if(t<y)y=t;
            z[t]++;
        }
    t=-1;
    for(map<int,int>::iterator p=z.begin();p!=z.end();p++){
        if(((p->first)-y)%d!=0){cout<<"-1";return 0;}
        int r=0;
        for(map<int,int>::iterator q=z.begin();q!=z.end();q++){
            r+=abs(p->first - q->first)/d * q->second;
        }
        if(r<t||t==-1)t=r;
    }
    cout<<t;
}