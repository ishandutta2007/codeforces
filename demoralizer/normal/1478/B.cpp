#include <iostream>
 
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        if(d==1){
            for(int i=0;i<n;i++){int c;cin>>c;cout<<"YES"<<endl;}
            continue;
        }
        int a[n];
        for(int i=0;i<n;i++){
            int b;
            cin>>a[i];
            if(a[i]>10*d){
                cout<<"YES"<<endl;
            }
            else{
                int k=0;
                while(k<d*10){
                    if((a[i]-k)<d){cout<<"NO"<<endl;k=-1;break;}
                    if((a[i] - k)%d==0&&a[i]!=k){
                        cout<<"YES"<<endl;k=-1;
                        break;
                    }
                    k=k+10;
                }
                if(k!=-1)
                cout << "NO\n";
            }
        }
    }
}