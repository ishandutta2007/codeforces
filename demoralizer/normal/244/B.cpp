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
int pw(int a,int b){
    int r=1;
    for(int i=0;i<b;i++)r*=a;
    return r;
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    int k=0,m=n,l=0;
    while(m!=0)k++,l=m%10,m/=10;
    if(k<3){
        cout<<n;
        r0;
    }
    m=9;
    for(int i=2;i<k;i++){
        m+=36*(pw(2,i)-2)+9;
        m+=9*(pw(2,i-1)-1);
    }
    for(int i=1;i<l;i++){
        m+=9*(pw(2,k-1)-1);
        m++;
    }
    for(int i=l*pw(10,k-1);i<=n;i++){
        int z=i;
        int a=-1,b=-1;
        while(z!=0){
            int d=z%10;
            if(d==a||a==-1)a=d;
            else if(d==b||b==-1)b=d;
            else break;
            z=z/10;
        }
        m+=(z==0);
    }
    cout<<m;
}