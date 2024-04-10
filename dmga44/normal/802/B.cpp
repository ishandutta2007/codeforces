#include <bits/stdc++.h>
using namespace std;

const int SIZE = 4e5 + 1;
int A[SIZE],UA[SIZE],tmp[SIZE],tmp3[SIZE];

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);

//    freopen(".in","r",stdin);

    int N,K;
    cin >> N >> K;

    for(int i = 1;i <= N;i++)
        cin >> A[i];

    fill(UA,UA + N + 1,SIZE);
    for(int i = N;i >= 1;i--){
        tmp[i] = UA[A[i]];
        UA[A[i]] = i;
    }

    unordered_set<int> lib;
    set<pair<int,int> > ord;
    int cost = 0;
    for(int i = 1;i <= N;i++){
        int aux = A[i];

        if(lib.find(aux) != lib.end()){
            ord.erase(make_pair(tmp3[aux],aux));
            tmp3[aux] = tmp[i];
            ord.insert(make_pair(tmp3[aux],aux));
            continue;
        }
        if(lib.size() < K){
            lib.insert(aux);
        }
        else{
            auto tmp2 = *(--ord.end());
            ord.erase(tmp2);

            lib.erase(tmp2.second);
            lib.insert(aux);
        }

        cost++;
        ord.erase(make_pair(tmp3[aux],aux));
        tmp3[aux] = tmp[i];
        ord.insert(make_pair(tmp3[aux],aux));
    }

    cout << cost << '\n';

    return 0;
}