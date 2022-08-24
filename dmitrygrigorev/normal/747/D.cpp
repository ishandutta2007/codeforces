#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <fstream>
using namespace std;
int n, k, ai;
vector<int> temp;
vector<int> dist;
bool UDgreater ( int elem1, int elem2 )
{
   return elem1 > elem2;
}
int main(){
    cin >> n >> k;
    for (int i=0;i<n;i++){
        cin >> ai;
        temp.push_back(ai);
    }
    int counter = 0;
    bool s = false;
    for (int i=0;i<n;i++){
        if (temp[i] < 0){
            if (!s){
            s = true;
            }
            else{
                if (counter > 0){
                    dist.push_back(counter);
                }
            }
            counter = 0;
        }
        else{
            counter ++;
        }
    }
    bool oo = false;
    int ooo = 0;
    if (counter > 0){
        oo = true;
        ooo = counter;
    }
    sort(dist.begin(), dist.end(), UDgreater);
    if (dist.size() == 0){
        int ccc = 0;
        for (int i=0;i<n;i++){
            if (temp[i] < 0){
                ccc ++;
            }
        }
        if (ccc == 0){
            cout << 0 << endl;
            return 0;
        }
        if (ccc <= k){
            if (ooo + ccc <= k){
            cout << 1 << endl;
            return 0;
            }
            else{
                cout << 2 << endl;
                return 0;
            }
        }
        cout << -1 << endl;
        return 0;
    }
    int summ = 0;
    int ccc = 0;
        for (int i=0;i<n;i++){
            if (temp[i] < 0){
                ccc ++;
            }
        }
        if (ccc > k){
            cout << -1 << endl;
            return 0;
        }
    int raznitsa = k - ccc;
    while (true){
        if (dist.size() == 0){
            break;
        }
            if (raznitsa - dist.back() >= 0){
                raznitsa -= dist.back();
                dist.pop_back();
            }
            else{
                break;
            }
    }
        if (!oo){
                cout << dist.size() * 2 + 1 << endl;
        }
        else{
            if (dist.size() == 0){
                if (!oo){
                    cout << 1 << endl;
                }
                else{
                    if (raznitsa - ooo >= 0){
                        cout << 1 << endl;
                        return 0;
                    }
                    cout << 2 << endl;
                }
            }
            else{
                    if (raznitsa - ooo >= 0){
                        cout << dist.size() * 2 + 1 << endl;
                        return 0;
                    }
                    cout << dist.size() * 2 + 2 << endl;
            }
        }
    return 0;
}