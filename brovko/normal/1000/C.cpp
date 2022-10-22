#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <pair <long long, int> > a;
long long n, k, l, cnt[200003], t;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> k >> l;
        a.push_back(make_pair(k, 0));
        a.push_back(make_pair(l+1, 1));
    }
    sort(a.begin(), a.end());
    for(int i=0;i<n*2-1;i++)
    {
        if(a[i].second==0)
            t++;
        else t--;
        cnt[t]=cnt[t]+a[i+1].first-a[i].first;
    }
    for(int i=1;i<=n;i++)
        cout << cnt[i] << ' ';
    return 0;
}