#include<bits/stdc++.h>
using namespace std;

int n,k;
char a[200005];
char b[200005];
bool f=true;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    cin>>a+1;
    for(int i=1;i<=k;i++){
        for(int j=i;j<=n;j+=k){
            b[j]=a[i];
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]>b[i]){
            f=false;
            break;
        }
        if(a[i]<b[i]){
            break;
        }
    }
    if(f){
        cout<<n<<endl;
        cout<<b+1<<endl;
        return 0;
    }
    int st=k;while(a[st]=='9')st--;
    for(int j=st;j<=n;j+=k){
        b[j]++;
    }
    for(int i=st+1;i<=k;i++){
        for(int j=i;j<=n;j+=k){
            if(b[j]=='9')b[j]='0';
        }
    }
    cout<<n<<endl;
    cout<<b+1<<endl;

    return 0;
}