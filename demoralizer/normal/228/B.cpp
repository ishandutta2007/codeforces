#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
int d[100005];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
int na,ma;
    cin>>na>>ma;
    int a[na+1][ma+1];
    for(int i=1;i<=na;i++){
        for(int j=1;j<=ma;j++){
            char c;
            cin>>c;
            a[i][j]=c-'0';
        }
    }
    int nb,mb;
    cin>>nb>>mb;
    int b[nb+1][mb+1];
    for(int i=1;i<=nb;i++){
        for(int j=1;j<=mb;j++){
            char c;
            cin>>c;
            b[i][j]=c-'0';
        }
    }
    int m=0,p=min(na,nb),q=min(ma,mb);
    for(int x=-50;x<=50;x++){
        for(int y=-50;y<=50;y++){
            int sum=0;
            for(int i=1;i<=na;i++){
                for(int j=1;j<=ma;j++){
                    if((x+i<=nb)&&(y+j<=mb)&&(x+i>=1)&&(y+j>=1))sum+=a[i][j]*b[i+x][j+y];
                }
            }
            if(sum>=m){
                m=sum;
                p=x;
                q=y;
            }
            //cout<<sum<<" "<<x<<" "<<y<<"\n";
        }
    }
    cout<<p<<" "<<q;
}