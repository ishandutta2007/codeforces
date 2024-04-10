#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<iomanip>

using namespace std;
    
char s[int(1e6) + 10];
stack<int>  st;
stack<int>  sec;

int main(){
   
    scanf("%s" , s);
    for (int i = 0 ; i < 1e6 + 10 ; i++){
	 if (s[i] != 'l' && s[i] != 'r') break;
	 if (s[i] == 'l')	st.push(i + 1);
	 else	  sec.push(i + 1);
    }
    while (!sec.empty()){
	 st.push(sec.top());
	 sec.pop();
    }	 
    while (!st.empty()){
	 printf("%d\n" , st.top());
	 st.pop();
    }
    return 0;
}