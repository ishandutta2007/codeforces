#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1e2 + 1;
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

    set<int> lib;
    int cost = 0;
    for(int i = 1;i <= N;i++){
        int aux = A[i];

        if(lib.find(aux) != lib.end()){
            tmp3[aux] = tmp[i];
            continue;
        }
        if(lib.size() < K){
            lib.insert(aux);
        }
        else{
            pair<int,int> tmp2(0,0);
            for(int j : lib){
                tmp2 = max(tmp2,make_pair(tmp3[j],j));
            }
            lib.erase(tmp2.second);
            lib.insert(aux);
        }

        cost++;
        tmp3[aux] = tmp[i];
    }

    cout << cost << '\n';

    return 0;
}