#include<iostream>
#include<vector>
#define ll long long
using namespace std;
/*
bool sortbysec(const pair<int,pair<int,int>> &a,
              const pair<int,pair<int,int>> &b)
{
    return (a.second.second < b.second.second);
}
*/
 
int main()
{
/*    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    int t=0;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ll> v(n);
        for(int i=0;i<n;++i)
        {
            cin>>v[i];
            if(v[i]&1)
            {
                v[i]+=(v[i]%10);
            }
        }
        bool b=1;
        bool c=0;
        for(int i=1;i<n;++i)
        {
            if(v[i]!=v[i-1]) b=0;
            if(v[i]%10==0) c=1;
        }
        if((v[0]%10)==0) c=1;
        if(b){
                cout<<"YES\n";
        continue;
        }
 
        if(c){
            cout<<"NO\n";
        continue;
        }
        vector<int> v248;
        vector<int> v6;
        bool e2=0;
        bool e6=0;
        for(int i=0;i<n;++i)
        {
            int x=(v[i]%10);
            if((x==2)||(x==4)||(x==8)){  v248.push_back(((v[i]%100)/10)%2);
            e2=1;
            }
            else{
                        v6.push_back(((v[i]%100)/10)%2);
                        e6=1;
            }
        }
        bool q=0;
        for(int i=1;i<v248.size();++i)
        {
            if(v248[i]!=v248[i-1]){
                q=1;
                break;
            }
        }
 
 
            if(q)
            {
                cout<<"NO\n";
                continue;
            }
        bool w=0;
        for(int i=1;i<v6.size();++i)
        {
            if(v6[i]!=v6[i-1]){
                w=1;
                break;
            }
        }
 
            if(w)
            {
                cout<<"NO\n";
                continue;
            }
 
            if(e2&&e6)
            {
                if(v6[0]!=v248[0])  cout<<"YES\n";
                else cout<<"NO\n";
            }
            else  cout<<"YES\n";
        //if(x==y)    cout<<"NO\n";
        //else           cout<<"YES\n";
    }
 
 
    return 0;
}