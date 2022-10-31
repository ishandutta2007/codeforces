

//
// Created by calabash_boy on 18-7-6.
//
#include<bits/stdc++.h>
#define F first
#define S second
#define PB(x) push_back(x)
#define debug(x) cout<<"[debug] "<<#x<<":"<<x<<endl;
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
const int MOD = -1;
const int maxn = 1e5+100;
int n,m;
vector<int> pri[maxn];
int phi[maxn];
bool flag[maxn];
int cnt;
int p[maxn];
void Get_phi()///
{
    cnt = 0;
    memset(flag, true, sizeof(flag));
    phi[1] = 1;
    for(int i=2; i<maxn; i++)///
    {
        if(flag[i])///
        {
            p[cnt++] = i;
            phi[i] = i-1;/// - 1
        }
        for(int j=0; j<cnt; j++)
        {
            if(i*p[j] > maxn)
                break;
            flag[i*p[j]] = false;///i*p[j]
            if(i%p[j] == 0)///i mod p == 0,  phi(i * p) == p * phi(i)
            {
                phi[i*p[j]] = p[j] * phi[i];
                break;
            }
            else
                phi[i*p[j]] = (p[j]-1) * phi[i];///i mod p != 0,  phi(i * p) == phi(i) * (p-1)
        }
    }
}
int begin[maxn];
int main(){
    Get_phi();
    scanf("%d%d",&n,&m);
    if (m<n-1||n==1&&m!=0){
        return puts("Impossible"),0;
    }
    LL cnt =0;
    for (int i=2;i<=n;i++){
        cnt+=phi[i];
    }
    if (m>cnt){
        return puts("Impossible"),0;
    }
    puts("Possible");
    //cout<<cnt<<endl;
    m-=n-1;
    for (int i=2;i<=n;i++){
        printf("%d %d\n",i,1);
    }
    if (!m)return 0;
    for (int i=3;i<=n;i++){
        for (int j=2;j<i;j++){
            if (__gcd(i,j)==1){
                printf("%d %d\n",i,j);
                m--;
                if (m==0){
                    return 0;
                }
            }
        }
    }
    return 0;
}