#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define MM 998244353
#define fr first
#define sc second
#define vc vector
#define pii pair<int,int>
#define msi map<string,int>
#define mii map<int,int>
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    char c[100],d[100];
    cin>>c;
    int n=strlen(c);
    if(n%2==0){
        int m=n/2-1;
        int i=0,j=0;
        d[j]=c[m+i];j++;
        for(int i=1;i<=m;i++){
            d[j]=c[m+i];
            j++;
            d[j]=c[m-i];
            j++;
        }
        d[n-1]=c[n-1];d[n]=0;cout<<d;
    }
    else{
        int m=n/2;
        int i=0,j=0;
        d[j]=c[m+i];j++;
        for(int i=1;i<=m;i++){
            d[j]=c[m+i];
            j++;
            d[j]=c[m-i];
            j++;
        }
        d[n]=0;cout<<d;
    }
}