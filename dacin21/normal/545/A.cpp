#include <iostream>
#include <queue>


using namespace std;

int main()
{
    int N;
    cin >> N;
    queue<int> q;
    int tmp;
    for(int i=0;i<N;++i){
        bool fail = false;;
      for(int j=0;j<N;++j){
        cin >> tmp;
        if(tmp == -1) continue;
        if((tmp&1)!=0){
          fail = true;
        }

      }
      if(!fail){
          q.push(i+1);
        }
    }

    cout << q.size() << "\n";
    while(!q.empty()){
      cout << q.front() << " ";
      q.pop();
    }
    return 0;
}