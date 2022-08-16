#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define r0 return 0
int hcf(int a,int b){
    if(a==0)return b;
    if(b==0)return a;
    return hcf(b%a,a);
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int x,y,n;
    cin>>x>>y>>n;
    int a=hcf(x,y);
    x/=a;
    y/=a;
    if(y<n){
        cout<<x<<"/"<<y;
        r0;
    }
    double p=1.0*x/y,q;
    set<pair<double, pair<int,int> > > s;
    for(int i=1;i<=n;i++){
        int k=(int)(i*p);
        q=abs(1.0*(x*i-k*y)/i*y);
        s.insert({q,{i,k}});
        k++;
        q=abs(1.0*(x*i-k*y)/i*y);
        s.insert({q,{i,k}});
    }
     cout<< ((*s.begin()).sc.sc) << "/" << ((*s.begin()).sc.fr);
}