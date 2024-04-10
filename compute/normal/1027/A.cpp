#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        string ss;
        cin>>n;
        cin>>ss;
        int flag=1;
        for(int i=0;i<n;i++)
        {
            if(abs(ss[i]-ss[n-i-1])>2||abs(ss[i]-ss[n-i-1])==1)
            {
                flag=0;
                break;
            }
        }
        if(flag)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}