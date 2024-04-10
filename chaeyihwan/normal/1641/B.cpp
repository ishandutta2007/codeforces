#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;

ll a[502];
stack<int> q;
queue<pair<int, int>> st;
int n;

void flip(int x)
{
    if(x == n) return;
    for(int i=n;i>=x;i--)
    {
        st.push({x-1+n-i, a[i]});
    }
    reverse(a+x, a+n+1);
    q.push(2*(n-x+1));
}

void ch(int x, int now)
{
    if(x > n/2)
    {
        flip(x);
        flip(n/2+now);
    }
    if(x <= n/2)
    {
        flip(n/2+1);
        flip(x);
        flip(x+now-1);
        flip(x);
        flip(n/2+1);
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];
        if(n%2 == 1)
        {
            cout << "-1\n";
            continue;
        }
        map<ll, int> cnt;
        cnt.clear();
        int pos = 0;
        for(int i=1;i<=n;i++)
        {
            cnt[a[i]]++;
            int tmp = cnt[a[i]];
            if(tmp%2) pos++;
            else pos--;
        }
        if(pos)
        {
            cout << "-1\n";
            continue;
        }

        while(!q.empty()) q.pop();
        while(!st.empty()) st.pop();

        for(int i=1;i<=n/2;i++)
        {
            if(a[i] == a[i+n/2]) continue;
            for(int j=i+1;j<=n/2;j++)
            {
                if(a[i] == a[j])
                {
                    ch(j, i);
                    break;
                }
                if(a[i] == a[j+n/2])
                {
                    ch(j+n/2, i);
                    break;
                }
            }
        }

        q.push(n);

        int s = st.size();
        assert(s <= 2*n*n);
        cout << st.size() << "\n";
        while(!st.empty())
        {
            cout << st.front().first << " " << st.front().second << "\n";
            st.pop();
        }
        cout << q.size() << "\n";
        while(!q.empty())
        {
            cout << q.top() << " ";
            q.pop();
        }
        cout << "\n";
    }
}