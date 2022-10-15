#include <bits/stdc++.h>

using namespace std;

int n,m,a[5],b[20],cnt_groups[1<<5],wanted_row_states,what[20];
int vis_mask[21][161051+1];

int get_val(int row_states,int pos){
  if(pos==0) return (row_states)%11;
  if(pos==1) return (row_states/11)%11;
  if(pos==2) return (row_states/11/11)%11;
  if(pos==3) return (row_states/11/11/11)%11;
  if(pos==4) return (row_states/11/11/11/11)%11;
}

int get_add_row_states(int row_states,int pos){
  if(pos==0) return row_states+1;
  if(pos==1) return row_states+11;
  if(pos==2) return row_states+11*11;
  if(pos==3) return row_states+11*11*11;
  if(pos==4) return row_states+11*11*11*11;
}

void explore(int col,int last_col_mask,int row_states){
  if(vis_mask[col][row_states]&(1<<last_col_mask))return;
  vis_mask[col][row_states]|=(1<<last_col_mask);
  if(col==m){
    if(row_states==wanted_row_states){
      for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(what[j]&(1<<i))cout<<"*";else cout<<".";
        }
        cout<<"\n";
      }
      exit(0);
    }
    return;
  }
  for(int mask=0;mask<(1<<n);mask++){
    if(cnt_groups[mask]!=b[col])continue;
    int new_row_states=row_states;
    for (int j=0;j<n;j++){
      if((mask&(1<<j))&&!(last_col_mask&(1<<j))) {
        new_row_states=get_add_row_states(new_row_states,j);
      }
    }
    what[col]=mask;
    explore(col+1,mask,new_row_states);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>a[i];
    for(int j=0;j<a[i];j++) {
      wanted_row_states=get_add_row_states(wanted_row_states,i);
    }
  }
  for(int i=0;i<m;i++)cin>>b[i];
  for(int mask=0;mask<(1<<n);mask++) {
    for(int i=0;i<n;i++)cnt_groups[mask]+=(mask&(1<<i))&&(i==0||!(mask&(1<<(i-1))));
  }
  explore(0,0,0);
}