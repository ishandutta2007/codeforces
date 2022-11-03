#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;

int main()
{
   // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);

    string home_name;
    string guest_name;

    cin >> home_name;
    cin >> guest_name;

    set<int> is_red;
    set<int> is_yellow;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int minute;
        cin >> minute;
        char from;
        cin >> from;
        int num;
        cin >> num;
        char tp;
        cin >> tp;

        if (from == 'h') {
            from = 0;
        } else {
            from = 1;
        }

        int big_num = num * 2 + from;

        if (is_red.find(big_num) != is_red.end()) {
            continue;
        }

        if (tp == 'y') {
            if (is_yellow.find(big_num) != is_yellow.end()) {
                is_red.insert(big_num);
            } else {
                is_yellow.insert(big_num);
            }
        } else if (tp == 'r') {
            is_red.insert(big_num);
        }

        if (is_red.find(big_num) != is_red.end()) {
            if (from == 0) {
                cout << home_name << " ";
            } else {
                cout << guest_name << " ";
            }
            cout << num << " ";
            cout << minute << endl;
        }
    }

    return 0;
}