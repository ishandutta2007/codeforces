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
#define MOD 1000000007
int used[26],cs;
int main(){
    int i,j,k,n,m;
    long long an=1;
    string str[100];
    cin>>n>>m;
    for(i=0;i<n;i++)cin>>str[i];
    for(i=0;i<m;i++){
        cs++;
        k=0;
        for(j=0;j<n;j++){
            if(used[str[j][i]]!=cs){
                k++;
                used[str[j][i]]=cs;
            }
        }
        an*=k;
        an%=MOD;
    }
    cout<<an<<endl;
    return 0;
}