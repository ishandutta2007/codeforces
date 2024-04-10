#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define SIZE 550
struct data{
    int x,y;
    data(int _x=0,int _y=0){x=_x,y=_y;}
};
vector<data>a[SIZE*SIZE],b[SIZE*SIZE];
int main(){
    int i,j,k,n,m,s;
    long long res=0;
    cin>>n>>m>>s;
    for(i=1;i<=n;i+=2)
        for(j=1;j<=m;j+=2){
            if(i*j==s){
                long long tmp=(i/2+1)*(j/2+1)*2-1;
                res+=tmp*(n-i+1)*(m-j+1);
            }
            else if(i*j>s){
                if((i*j-s)%4==0){
                    int r=(i*j-s)/4;
                    for(int ii=1;ii*2+1<=i;ii++){
                        if(r%ii)continue;
                        int jj=r/ii;
                        if(jj*2+1>j)continue;
                        res+=2ll*(n-i+1)*(m-j+1);
                    }
                }
            }
        }
    cout<<res<<endl;
    return 0;
}