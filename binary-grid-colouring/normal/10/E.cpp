#include<bits/stdc++.h>
using namespace std;
int n,ans,a[500],b[500],c[500];  
int solve(int x)  
{  
    int ans = 0;  
    for(int i = 1;i <= n;i++)  
    {  
        b[i] = x / a[i];  
        ans  += b[i];  
        x %= a[i];  
        if(!x) break;   
    }   
    return ans;  
}  
int main()  
{  
    ans = 2e9;  
    cin>>n;  
    for(int i = 1;i <= n;i++) cin>>a[i];  
    
    for(int i = 1;i < n;i++)  
    {  
        solve(a[i]-1);   
        for(int i = 1;i <= n;i++) c[i] = b[i];  
        for(int j = i+1;j <= n;j++)  
        {  
            int temp = 0,temp2 = 0;  
            for(int k = 1;k <= j;k++)   
            {  
                temp2 += a[k]*c[k];  
                temp += c[k];  
            }  
            temp2 += a[j],temp++;  
            if(solve(temp2) > temp) ans = min(temp2,ans);  
        }  
    }  
    if(ans == 2e9) cout<<-1<<endl;  
    else cout<<ans<<endl;  
    return 0;
}