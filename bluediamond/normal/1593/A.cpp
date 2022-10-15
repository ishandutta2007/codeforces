
#include <bits/stdc++.h>


using namespace std;




int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int t;
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        int a,b,c,mx=0,cnt=0;
        cin>>a>>b>>c;
        mx=max(a,max(b,c));
        cnt=(a==mx)+(b==mx)+(c==mx);
        cout<<mx-a+1-(a==mx)*(cnt==1)<<" "<<mx-b+1-(b==mx)*(cnt==1)<<" "<<mx-c+1-(c==mx)*(cnt==1)<<"\n";
        cout<<"\n";
    }
}