#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int max_a = 1e6;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    vector<int> f(n);
    vector<int> b(n);

    vector<int> id_f(max_a + 1, -1);
    vector<int> id_b(max_a + 1, -1);
    
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
        cin >> b[i];
        
        id_f[f[i]] = i;
        id_b[b[i]] = i;
    }
    
    vector<int> ans(n);
    
    int root = 0;
    for (int i = 0; i <= max_a; ++i) {
        if (id_f[i] != -1 && id_b[i] == -1) {
            root = i;
            break;
        }
    }
    
    int id_root = id_f[0];
    for (int i = 0; i < n; ++i) {
        ans[i] = root;
        
        int id_prev_root = id_f[root];
        
        root = b[id_root];
        id_root = id_prev_root;
    }
    
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}