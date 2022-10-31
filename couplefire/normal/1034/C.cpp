#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAX 1000005
#define ll long long int
 
ll C[MAX];
int A[MAX];
int P[MAX];
int Ans[MAX];
int Sum[MAX];
int Ret[MAX];
int Count[MAX];
int Add(int a,int b){return (a+b)>=MOD ? a+b-MOD : a+b;}
 
int main() {
    int n;
    scanf("%d",&n);
 
    for(int i=1;i<=n;i++) scanf("%d",&A[i]), C[i]=A[i];
    for(int i=2;i<=n;i++) scanf("%d",&P[i]);
    for(int i=n;i>=2;i--) C[P[i]]+=C[i];
 
    for(int i=1;i<=n;i++) {
        ll G=__gcd(C[1],C[i]); G=C[1]/G;
        if(G<=n) Count[G]++;
    }
 
    for(int i=1;i<=n;i++) for(int j=i;j<=n;j+=i) Sum[j]+=Count[i];
 
    for(int i=n;i>=1;i--){
        if(Sum[i]==i){
            Ans[i]++;
            for(int j=i+i;j<=n;j+=i) Ans[i]=Add(Ans[i],Ans[j]);
        }
    }
    cout<<Ans[1]<<endl;
}