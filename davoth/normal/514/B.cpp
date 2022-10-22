#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,ans=0,x,y,a,b,f=0,k=0;
    double result,t1,t2;
    vector<double>arr;
    cin>>n>>x>>y;
    if(n==1){
        cin>>a>>b;
        cout<<"1";
    }else{
        for(int i=0;i<n;i++){
            cin>>a>>b;
            t1=b-y;
            t2=a-x;
            if(t2==0)
                arr.push_back(INT_MAX);
            else if(t2!=0)
                arr.push_back(t1/t2);
        }
        sort(arr.begin(),arr.end());
        ans=1;
        for(int i=1;i<arr.size();i++)
            if(arr[i]!=arr[i-1])
                ans++;
        cout<<ans;
    }
    return 0;
}