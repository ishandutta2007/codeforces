#include <bits/stdc++.h>
using namespace std;

int main() {
  long long MAX = pow(2, 32)-1;
  int n;
  cin >> n;
  stack<int> fors;
  long long val = 0;
  long long num = 1;

  int i = 0;
  while(i != n){
    string str;
    cin >> str;
    if(str == "add"){
      val += num;
    }
    else if(str == "for"){
      int j;
      cin >> j;
      num *= j;
      fors.push(j);
    }
    else{
      num /= fors.top();
      fors.pop();
    }
    if(val > MAX){
      cout << "OVERFLOW!!!" << endl;
      return 0;
    }
    if(num > MAX){
      int end = 1;
      while(end != 0){
        string s;
        cin >> s;
        if(s == "add"){
          cout << "OVERFLOW!!!" << endl;
          return 0;
        }
        else if(s == "for"){
          int k;
          cin >> k;
          end++;
        }
        else{
          end--;
        }
        i++;
      }
      num /= fors.top();
      fors.pop();
    }
    i++;
  }
  cout << val << endl;
}

/*
30
for 100
for 100
for 100
for 100
for 100
for 100
for 100
for 100
for 100
for 100
for 100
for 100
for 100
for 100
add
end
end
add
end
end
end
end
end
end
end
end
end
end
end
end

*/