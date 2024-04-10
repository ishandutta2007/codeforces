#include <bits/stdc++.h>

using namespace std;

string a[10],b[10];
bool viz[10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    a[1]="Power";
    a[2]="Time";
    a[3]="Space";
    a[4]="Soul";
    a[5]="Reality";
    a[6]="Mind";

    b[1]="purple";
    b[2]="green";
    b[3]="blue";
    b[4]="orange";
    b[5]="red";
    b[6]="yellow";

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string x;
        cin>>x;
        for(int j=1;j<=6;j++){
            if(b[j]==x){
                viz[j]=1;
            }
        }
    }

    cout<<6-n<<"\n";

    for(int i=1;i<=6;i++){
        if(viz[i]==0){
            cout<<a[i]<<"\n";
        }
    }
    return 0;
}
/**

**/