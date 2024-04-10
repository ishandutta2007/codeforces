#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
const double EPS=1e-8;
const ll INF=ll(1e18);
const int sINF=int(1e8);
typedef pair<int,int> ii;
typedef set<int>::iterator isit;
int m;
string s;
int len;
priority_queue<char> q;
vector<bool> used;
void nxt(int f,int t)
{
    if(f>=len)return;
    int r=min(t,len-1);
    for(int i=r;i>=f;i--)
    {
        if(s[i]<s[r])r=i;
    }
    if(s[r]!='0')q.push(s[r]);
    used[r]=true;
    nxt(r+1,r+m);
}
int main()
{
    cin>>m>>s;
    s+="0";
    len=s.length();
    used.resize(len);
    fill(used.begin(),used.end(),false);
    nxt(0,m-1);
    for(int i=0;i<len;i++)
    {
        if(!used[i]&&int(q.top())>int(s[i]))q.push(s[i]);
    }
    stack<char> st;
    while(!q.empty())
    {
        st.push(q.top());
        q.pop();
    }
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
    cout<<endl;
}