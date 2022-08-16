#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> a(N);
    copy_n(istream_iterator<int>(cin), N, a.begin());
    for(int i=0;i<N;++i){
      for(int j=N-2;j>=i;--j){
        if(a[j]>a[j+1]){
          swap(a[j], a[j+1]);
          cout << j+1 << " " << j+2 << "\n";
        }
      }
    }
    //copy(a.begin(), a.end(), ostream_iterator<int>(cerr, " "));
    return 0;
}