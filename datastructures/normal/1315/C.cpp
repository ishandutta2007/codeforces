#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t,n,b[1005],a[1005],book[1005];
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        memset(book,0,sizeof(book));
        memset(a,0,sizeof(a));
        for (int i=1;i<=n;i++)cin>>b[i];
        for (int i=1;i<=n;i++)a[i*2-1]=b[i],book[b[i]]=1;
        int flag=1;
        for (int i=1;i<=n;i++){
            for (int j=b[i];j<=2*n;j++){
                if (book[j]==0){
                    book[j]=1;
                    a[i*2]=j;
                    break;
                }
            }
            if (a[i*2]==0)flag=0;
        }
        if (flag==0)cout<<-1<<endl;
        else{
            for (int i=1;i<=2*n;i++)cout<<a[i]<<' ';
            cout<<endl;
        }
    }
    return 0;
}