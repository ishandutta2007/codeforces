program task_1;

{$APPTYPE CONSOLE}

const dx: array[1..8]of integer=(-1,-1,-1,0,0,1,1,1);
      dy: array[1..8]of integer=(-1,0,1,-1,1,-1,0,1);
var Used: array[1..8,1..8,0..9]of boolean;
    Head: array[1..8]of integer;
    Next,Pos: array[1..64]of integer;
    Map: array[1..8,1..8]of char;
    ls,t,tt,i,j: integer;

procedure dfs(y,x,h: integer);
var i,xx,yy: integer;
begin
  if (h>=8)then begin
    writeln('WIN');
    halt;
  end;
  Used[y,x,h]:=true;
  for i:=1 to 8 do begin
    xx:=x+dx[i];yy:=y+dy[i];
    if (xx>=1)and(xx<=8)and
       (yy>=1)and(yy<=8)and
       (not Used[yy,xx,h+1])and(not Used[yy,xx,h])then
        dfs(yy,xx,h+1);
  end;
  if (not Used[y,x,h+1])then dfs(y,x,h+1);
  Used[y,x,h]:=false;
end;

begin
//assign(input,'input.txt');reset(input);
//assign(output,'output.txt');rewrite(output);
  fillchar(Head,sizeof(Head),-1);
  ls:=0;
  for i:=1 to 8 do begin
    for j:=1 to 8 do begin
      read(Map[i,j]);
      if (Map[i,j]='S')then begin
        inc(ls);
        Next[ls]:=Head[j];
        Head[j]:=ls;
        Pos[ls]:=i;
      end;
    end;
    readln;
  end;
  fillchar(Used,sizeof(Used),false);
  for i:=1 to 8 do begin
    j:=Head[i];
    while (j<>-1)do begin
      t:=Pos[j];tt:=0;
      while (t<=8)do begin
        Used[t,i,tt]:=true;
        inc(t);inc(tt);
      end;
      j:=Next[j];
    end;
  end;
  dfs(8,1,0);
  writeln('LOSE');
end.