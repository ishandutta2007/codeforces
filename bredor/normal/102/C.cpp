//  228

#include<bits/stdc++.h>
using namespace std;
#define ll                long long int
#define ld                long double
#define Pore              ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define debug(x)          cout << #x << " is " << x << endl;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define fi                first
#define se                second
#define ii                pair<ll,ll>
#define iii               pair<ll,ii>
#define endl              '\n'
#define sz                size
#define all(x)            (x).begin(),(x).end()
const int mod  = 1e9 + 7;

void ggg() {
    Pore
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int N = 1e6 + 5;

ii cnt[26];
int del[26];


int main() {
    ggg();

    string s;
    int k;
    cin >>  s >> k;
    int n = s.size();
    int m = 26;
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a'].first++;
    }
    for (int i = 0; i < 26; i++)
        cnt[i].second = i;
    sort(cnt, cnt + 26);
    ll sum = 0;
    for (int i = 0; i < 26; i++) {
        sum += cnt[i].first;
        if (sum > k)
            break;
        del[cnt[i].second] = 1;
        m--;
    }
    cout << m << endl;
    for (int i = 0; i < n; i++) {
        if (!del[s[i] - 'a'])
            cout << s[i];
    }
    return 0;
}