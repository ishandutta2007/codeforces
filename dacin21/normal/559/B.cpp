#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <algorithm>

using namespace std;
  string a, b;

  bool equ(int a1, int b1, int length){
    for(int i=0;i<length;++i){
        if(a[a1+i] != b[b1+i]){
          return false;
        }
      }
      return true;
  }

  bool solve(int a1, int b1, int length){
    if(equ(a1, b1, length)) return true;
    if(length&1) return false;
  /*string tmp1, tmp2, tmp3, tmp4;
    tmp1 = a.substr(a1, length/2);
    tmp2 = a.substr(a1 + length/2, length/2);
    tmp3 = b.substr(b1, length/2);
    tmp4 = b.substr(b1 + length/2, length/2);
    if(tmp1==tmp3 && tmp2 == tmp4) return true;
    if(tmp1==tmp4 && tmp2 == tmp3) return true;
    sort(tmp1.begin(), tmp1.end());
    sort(tmp2.begin(), tmp2.end());
    sort(tmp3.begin(), tmp3.end());
    sort(tmp4.begin(), tmp4.end());*/
    /*bool sucess = false;
    if(tmp1==tmp3 && tmp2==tmp4){
      sucess|=(solve(a1, b1, length/2) && solve(a1+length/2, b1+length/2, length/2));
    } if(tmp1==tmp4 && tmp2 == tmp3){
      sucess|=(solve(a1 + length/2, b1, length/2) && solve(a1, b1+length/2, length/2));
    }*/
      //return sucess;
      return  (solve(a1, b1, length/2) && solve(a1+length/2, b1+length/2, length/2)) || (solve(a1 + length/2, b1, length/2) && solve(a1, b1+length/2, length/2));
  }

int main()
{
  cin >> a >> b;
  if(a.size() != b.size()){
    cout << "NO";
    return 0;
  }

  cout << (solve(0, 0, a.size()) ? "YES" : "NO");

  /*queue<pair<pair<int, int> , pair<int, int> > > q;
  q.emplace(make_pair(0, a.size()), make_pair(0, b.size()));

  pair<int, int> pa, pb;
  string tmp1, tmp2, tmp3, tmp4;
  while(!q.empty()){
    pa=q.front().first;
    pb=q.front().second;
    q.pop();

    if((pa.second&1)){
      for(int i=0;i<pa.second;++i){
        if(a[pa.first+i] != b[pb.first+i]){
          cout << "NO";
          return 0;
        }
      }
      continue;
    }
    tmp1 = a.substr(pa.first, pa.second/2);
    tmp2 = a.substr(pa.first + pa.second/2, pa.second/2);
    tmp3 = b.substr(pb.first, pb.second/2);
    tmp4 = b.substr(pb.first + pb.second/2, pb.second/2);
    if(tmp1==tmp2) continue;
    sort(tmp1.begin(), tmp1.end());
    sort(tmp2.begin(), tmp2.end());
    sort(tmp3.begin(), tmp3.end());
    sort(tmp4.begin(), tmp4.end());
    if(tmp1==tmp3 && tmp2==tmp4){
      q.emplace(make_pair(pa.first, pa.second/2), make_pair(pb.first, pb.second/2));
      q.emplace(make_pair(pa.first + pa.second/2, pa.second/2), make_pair(pb.first +  pb.second/2, pb.second/2));
    } else if(tmp1==tmp4 && tmp2 == tmp3){
      q.emplace(make_pair(pa.first, pa.second/2), make_pair(pb.first +  pb.second/2, pb.second/2));
      q.emplace(make_pair(pa.first + pa.second/2, pa.second/2), make_pair(pb.first , pb.second/2));
    } else {
    cout << "NO";
      return 0;
    }
  }

   cout << "YES";*/

  return 0;
}