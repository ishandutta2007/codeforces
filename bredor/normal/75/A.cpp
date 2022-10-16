//  228

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int sum = n + m;
    string n1, n2, n3;
    n1 = to_string(n);
    n2 = to_string(m);
    n3 = to_string(sum);
    int i = 0, j = 0, k = 0;
    int n1_len = n1.length(), n2_len = n2.length(), n3_len = n3.length();
    while (i < n1_len || j < n2_len || k < n3_len)
    {
        if (n1[i] == '0')
        {
            n1.erase(n1.begin() + i);
            i = 0;
            n1_len = n1.length();
        }
        if (n2[j] == '0')
        {
            n2.erase(n2.begin() + j);
            j = 0;
            n2_len = n2.length();
        }
        if (n3[k] == '0')
        {
            n3.erase(n3.begin() + k);
            k = 0;
            n3_len = n3.length();
        }
        i++;
        j++;
        k++;
    }
    int n4, n5, n6;
    n4 = stoi(n1);
    n5 = stoi(n2);
    n6 = stoi(n3);
    if (n4 + n5 != n6)
    {
        cout << "NO" << endl;
    }
    else
        cout << "YES" << endl;
}