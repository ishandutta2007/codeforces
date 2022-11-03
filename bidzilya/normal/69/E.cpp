#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define maxint (int)1e9
#define eps 1e-9

map <int,int> p;
set <int> s;
int n,k;
int a[100000];

int main(){
        cin >> n >> k;
        int l=0,r=k-1;
        for (int i=0;i<n;i++){
            cin >> a[i];
            switch (++p[a[i]]){
                case 1: s.insert(a[i]);
                        break;
                case 2: s.erase(a[i]);
                        break;
            }

            if (i>=k-1){
                if (s.empty())
                    cout << "Nothing" << endl;
                else
                    cout << *s.rbegin() << endl;
                switch (--p[a[i-k+1]]){
                     case 0: s.erase(a[i-k+1]);
                            break;
                     case 1: s.insert(a[i-k+1]);
                            break;
                }
            }
        }
	return 0;
}