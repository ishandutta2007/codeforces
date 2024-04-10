#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,volume;
    cin >> n >> volume;
    vector<pair<int,int> > o,t;
    int sz,val;
    for(int i=0;i<n;i++)
    {
        cin >> sz >> val;
        if(sz==1) o.push_back(make_pair(val,i));
        else t.push_back(make_pair(val,i));
    }
    sort(o.begin(),o.end());
    o.push_back(make_pair(0,-1));
    reverse(o.begin(),o.end());
    sort(t.begin(),t.end());
    t.push_back(make_pair(0,-1));
    reverse(t.begin(),t.end());
    int no=o.size()-1;
    int nt=t.size()-1;
    for(int i=1;i<=no;i++) o[i].first+=o[i-1].first;
    for(int i=1;i<=nt;i++) t[i].first+=t[i-1].first;
    int m=0,idx=0;
    for(int i=0;i<=nt;i++)
    {
        if(2*i>volume) break;
        int cur=t[i].first+o[min(volume-2*i,no)].first;
        if(cur>m)
        {
            m=cur;
            idx=i;
        }
    }
    cout << m << endl;
    for(int i=idx;i>=1;i--) cout << t[i].second+1 << " ";
    for(int i=min(volume-2*idx,no);i>=1;i--) cout << o[i].second+1 << " ";
    cout << endl;
    return 0;
}