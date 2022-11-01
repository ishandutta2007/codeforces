#include<bits/stdc++.h>
using namespace std;
int a[6], b[6];

int main()
{
    int n, x, y;
    cin>>n;
    if(n==1){
        cin>>x>>y;
        if(x==y)    printf("0\n");
        else printf("-1\n");
        return 0;
    }
    int count_a=0;
	int count_b=0;
    for(int i=0; i<n; i++){
       cin>>x;
       a[x]++;
    }
    for(int i=0; i<n; i++){
        cin>>y;
        b[y]++;
    }
    for(int i=1; i<=5; i++){
        if((a[i]+b[i])%2==0){
            if(a[i]>b[i])    count_a += (a[i]-b[i])/2;
            else if(a[i]<b[i]) count_b += (b[i]-a[i])/2;
        }
        else{
            return 0*printf("-1\n"); 
        }
    }
    cout<<count_a<<endl;    
    return 0;
}