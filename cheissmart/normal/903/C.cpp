#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main()
{
    int n, a[5000];
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a, a+n, cmp);
    v.push_back(a[0]);
    for(int i=1;i<n;i++) {
        for(int j=0;j<v.size();j++) {
            if(a[i] < v[j]) {
                v[j] = a[i];
                break;
            } else if(j == v.size() - 1) {
                v.push_back(a[i]);
                break;
            }
        }
    }
    cout << v.size() << endl;
}