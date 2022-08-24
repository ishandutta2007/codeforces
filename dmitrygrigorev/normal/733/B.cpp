#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
    vector<vector<int> >data;
    int mod(int number){
        if (number >=0) {
            return number;
        }
        return number * (-1);
    }

int main()
{
    int n;
    cin >> n;
    int a, b;
    int r = 0;
    for (int i=0; i<n;i++){
        vector<int> help;
        cin >> a >> b;
        help.push_back((b - a) * 2);
        help.push_back(i);
        r += b-a;
        data.push_back(help);
    }
    sort(data.begin(), data.end());
    int result = mod(r - data[0][0]);
    int r1 = mod(r - data[data.size() - 1][0]);
    if (max(mod(result), mod(r1)) > mod(r)){
    if (mod(result) <= mod(r1)){
        cout << data[data.size() - 1][1] + 1 << endl;
    }
    else{
        cout << data[0][1] + 1 << endl;
    }
    }
    else{
        cout << 0 << endl;
    }
    return 0;
}