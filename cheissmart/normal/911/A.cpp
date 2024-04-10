#include <iostream>
#include <vector>

#define inf (int) 1e9

using namespace std;

int main()
{
    int n, mi = inf;
    cin >> n;
    vector<int> v(n), pos;
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<n;i++) {
        if(v[i] < mi){
            mi = v[i];
            pos.clear();
            pos.push_back(i);
        } else if(v[i] == mi){
            pos.push_back(i);
        }
    }
    int mindis = inf;
    for(int i=0;i<pos.size()-1;i++)
        mindis = min(mindis, pos[i+1]-pos[i]);
    cout << mindis << endl;
}