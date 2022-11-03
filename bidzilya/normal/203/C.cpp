#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,d,s1,s2;
pair<int,int> a[111111];

int main(){
    cin >> n >> d >> s1 >> s2;
    for (int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        a[i] = make_pair(x*s1+y*s2,i+1);
    }
    sort(a, a+n);
    vector<int> ans;
    for (int i=0;i<n;i++)
        if (d>=a[i].first)
        {
                    ans.push_back(a[i].second);
                    d -= a[i].first;
        }
    cout << ans.size() << endl;
    for (int i=0;i<ans.size();i++)
        cout << ans[i] << " ";
    return 0;
}