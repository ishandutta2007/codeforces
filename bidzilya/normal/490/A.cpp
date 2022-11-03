#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> tp(n);
    for (int i = 0; i < n; ++i) {
        cin >> tp[i];
    }
    
    vector<bool> used(n, false);
    
    vector<int> ans1, ans2, ans3;
    
    while (true) {
        int t1, t2, t3;
        t1 = -1;
        for (int i = 0; i < n; ++i) {
            if (!used[i] && tp[i] == 1) {
                t1 = i;
                break;
            }
        }
        t2 = -1;
        for (int i = 0; i < n; ++i) {
            if (!used[i] && tp[i] == 2) {
                t2 = i;
                break;
            }
        }
        t3 = -1;
        for (int i = 0; i < n; ++i) {
            if (!used[i] && tp[i] == 3) {
                t3 = i;
                break;
            }
        }
        if (t1 == -1 || t2 == -1 || t3 == -1) {
            break;
        }
        
        used[t1] = true;
        used[t2] = true;
        used[t3] = true;
        
        ans1.push_back(t1);
        ans2.push_back(t2);
        ans3.push_back(t3);
    }
    
    cout << (int) ans1.size() << endl;
    for (int i = 0; i < (int) ans1.size(); ++i) {
        cout << ans1[i] + 1 << " " << ans2[i] + 1 << " " << ans3[i] + 1 << endl;
    }
    
    return 0;
}