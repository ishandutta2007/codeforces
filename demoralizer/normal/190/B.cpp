#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define r0 return 0
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    double p;
    cout<<setprecision(9);
    int a,b,c,x,y,z;
    cin>>a>>b>>c>>x>>y>>z;
    p=sqrt((a-x)*(a-x)+(b-y)*(b-y))-c-z;
    if(p<0){
        p+=c+z;
        if(p<abs(c-z)){
            p=abs(c-z)-p;
        }
        else p=0;
    }
    p/=2;
    cout<<p;
}