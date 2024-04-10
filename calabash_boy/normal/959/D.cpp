#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1.45e6+100;
int a[maxn],n;
bool used[maxn];
int prime[maxn],tot;
bool vis[maxn];
vector<int>fac[200000];
int ans[100000],nn;
void init(){
    vis[1]=1;
    for (int i=2;i<maxn;i++){
        if (!vis[i]){
            prime[tot++] = i;
        }
        for (int j=0;j<tot&&1LL*i*prime[j]<maxn;j++){
            vis[i*prime[j]]=1;
            if(!(i%prime[j]))break;
        }
    }
    for (int i=2;i<=200000;i++){
        for (int j=1;1LL*j*j<=i;j++){
            if(i%j==0){
                if(!vis[j])fac[i].push_back(j);
                int tt = i/j;
                if(tt==j||vis[tt])continue;
                fac[i].push_back(tt);
            }
        }
    }
  // cout<<tot<<endl;
}
int main(){
    init();
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    for (int i=0;i<n;i++){
        bool flag = false;
        for (int p:fac[a[i]]){
            if(used[p]){
                flag=true;
                break;
            }
        }
        if(!flag){
            ans[nn++] =a[i];
            for (int p:fac[a[i]]){
                used[p]=1;
            }
        }else{
            break;
        }
    }
  //  cout<<nn<<endl;
    if(nn!=n){
        for (int j=a[nn]+1;j<maxn;j++){
            bool flag = true;
            for (int p:fac[j]){
                if(used[p]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans[nn++] = j;
                for (int p:fac[j]){
                    used[p]=1;
                }
                break;
            }
        }
        int j=0;
        for (int i=nn;i<n;i++){
            while (used[prime[j]])j++;
            ans[i] = prime[j++];
        }
    }
    for (int i=0;i<n;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}