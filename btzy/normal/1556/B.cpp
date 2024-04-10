#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 100000;
bool arr[MAXN];
int allay(int offset, int n){
    int net=0;
    int val=0;
    for(int i=0;i<n;++i){
        if(arr[i]){
            val+=abs(net-offset);
            ++offset;
        }
        else {
            ++net;
        }
    }
    return val;
}
int main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int ct=0;ct<tc;++ct){
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            int tmp;
            cin>>tmp;
            arr[i]=(tmp&1);
        }
        int num0=0,num1=0;
        for(int i=0;i<n;++i){
            if(arr[i])++num1;
            else ++num0;
        }
        int best=INT_MAX;
        if(num1==num0){
            int tmp = allay(0,n);
            best=min(best,tmp);
            tmp=allay(1,n);
            best=min(best,tmp);
        }
        else if (num1+1==num0){
            int tmp=allay(1,n);
            best=min(best,tmp);
        }
        else if(num0+1==num1){
            int tmp = allay(0,n);
            best=min(best,tmp);
        }
        if(best==INT_MAX)best=-1;
        cout<<best<<'\n';
    }
}