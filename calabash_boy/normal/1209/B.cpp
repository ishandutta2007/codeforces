#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int ans[100000+5];
char s[maxn];
int a[maxn];
int b[maxn];
int main(){
    int n;
    cin>>n;
    cin>>s+1;
    for (int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        if (s[i] == '0'){
            for (int st = b[i];st < 100000;st += 2 * a[i]){
                for (int j=0;j<a[i];j++){
                    ans[st + j] ++;
                }
            }
        }else{
            for (int j=0;j<b[i];j++)ans[j] ++;
            for (int st = b[i]+a[i];st < 100000;st += 2 * a[i]){
                for (int j=0;j<a[i];j++){
                    ans[st + j] ++;
                }
            }
        }
 
    }
    int true_ans = 0;
    for (int i=0;i<100000;i++){
        true_ans = max(true_ans,ans[i]);
    }
    cout<<true_ans<<endl;
    return 0;
}