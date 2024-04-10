#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

int n,m;
pair<int,int> p[maxn];
int cnt;

void otp(){
    cout<<"Possible\n";
    for(int i=1;i<=m;i++){
       cout<<p[i].first<<' '<<p[i].second<<'\n';
    }
}

inline int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
    cin>>n>>m;
    if(m<n-1){
        cout<<"Impossible";
        return 0;
    }
    cnt=n-1;
    for(int i=1;i<n;i++){
        p[i].first=1;
        p[i].second=i+1;
    }
    if(m==cnt){
        otp();return 0;
    }
    for(int i=2;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(gcd(i,j)==1){
                p[++cnt].first=i;
                p[cnt].second=j;
                if(cnt==m){
                    otp();return 0;
                }
            }
        }
    }
    cout<<"Impossible";
    return 0;
}