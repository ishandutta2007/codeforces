#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, ans=0;
    cin>>n;
    set <int> se, se2;
    vector <int> st;
    for(int a=0; a<n*2; a++)
    {
        string s;
        cin>>s;
        if(s=="add")
        {
            int x;
            cin>>x;
            st.push_back(x);
            se2.insert(x);
        }
        else
        {
            //cout<<st.size()<<" ";
            if(st.size()==0) se.erase(se.begin());
            else
            {
                if(st.back()==(*se2.begin())) st.pop_back();
                else
                {
                    for(int a=0; a<st.size(); a++) se.insert(st[a]);
                    se.erase(se.begin());
                    ans++;
                    st.clear();
                }
            }
            se2.erase(se2.begin());
        }
    }
    cout<<ans;
}