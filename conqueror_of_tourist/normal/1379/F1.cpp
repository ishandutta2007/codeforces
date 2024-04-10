#include <iostream> 
#include <algorithm> 
using namespace std;
 
typedef long long ll;
 
int BIG = 10000010;
 
 
int main() {
    int n;
    int m;
    int q;
    cin >> n >> m >> q;
    
    int lo = 0;
    int hi = q + 1;
    
    pair<int,int> queries[q];
    int a;
    int b;
    for (int i = 0; i < q; i++){
        cin >> a >> b;
        queries[i] = make_pair(a-1,b-1);
    }
    
    pair<int,int> real[q];
    
    while (hi - lo > 1){
        int test = (hi + lo)/2;
        for (int i = 0; i < test; i++) real[i] = queries[i];
        
        sort(real, real + test);
        
        int worst = 2*n + 2*m + 100;
        bool works = true;
        
        for (int i = 0; i < test; i++){
            if (real[i].first & 1){
                if (real[i].second >= worst){
                    works = false;
                    break;
                }
            }
            else{
                if (real[i].second < worst) worst = real[i].second;
            }
        }
        
        if (works){
            lo = test;
        }
        else{
            hi = test;
        }
    }
    
    for(int i = 0; i < lo; i++){
        cout << "Yes" << "\n";
    }
    for(int i = 0; i < q - lo; i++){
        cout << "No" << "\n";
    }
    
    return 0;
}