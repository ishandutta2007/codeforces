#include<bits/stdc++.h>
using namespace std;

int n;
int a[150005];
int low,cnt;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    low=1;
    for(int i=1;i<=n;i++){
        if(a[i]>low){
            a[i]--;
            cnt++;
            low=max(low,a[i]+1);
        }else{
            if(a[i]==low){
                cnt++;
                low=a[i]+1;
            }else{
                if(a[i]+1==low){
                    a[i]++;
                    cnt++;
                    low++;
                }else{
                    continue;
                }
            }
        }
    }
    cout<<cnt<<endl;

    return 0;
}