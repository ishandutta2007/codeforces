program task_b;

{$APPTYPE CONSOLE}
uses Math, SysUtils;
var s,name: string;
    n,nn,i,k1,k2,k3,ta1,ta2,ta3,tmp,l1,l2,l3: integer;
    ans1,ans2,ans3: array[1..100]of string;


begin
//assign(input,'input.txt');reset(input);
//assign(output,'output.txt');rewrite(output);
  readln(nn);
  ta1:=0;l1:=0;
  ta2:=0;l2:=0;
  ta3:=0;l3:=0;
  for nn:=1 to nn do begin
    readln(s);
    tmp:=pos(' ',s);
    name:=copy(s,tmp+1,length(s)-tmp);
    n:=strtoint(copy(s,1,tmp-1));
    k1:=0;
    k2:=0;
    k3:=0;
    for i:=1 to n do begin
      readln(s);
      if (s[1]=s[2])and(s[2]=s[4])and(s[4]=s[5])and(s[5]=s[7])and(s[7]=s[8])then inc(k1)
      else
      if (s[1]>s[2])and(s[2]>s[4])and(s[4]>s[5])and(s[5]>s[7])and(s[7]>s[8])then inc(k2)
      else
      inc(k3);
    end;
    if (k1=ta1)then begin
      inc(l1);
      ans1[l1]:=name;
    end;
    if (k1>ta1)then begin
      l1:=1;
      ans1[1]:=name;
      ta1:=k1;
    end;
    if (k2=ta2)then begin
      inc(l2);
      ans2[l2]:=name;
    end;
    if (k2>ta2)then begin
      l2:=1;
      ans2[1]:=name;
      ta2:=k2;
    end;
    if (k3=ta3)then begin
      inc(l3);
      ans3[l3]:=name;
    end;
    if (k3>ta3)then begin
      l3:=1;
      ans3[1]:=name;
      ta3:=k3;
    end;
  end;
  write('If you want to call a taxi, you should call: ');
  for i:=1 to l1-1 do write(ans1[i],', ');
  writeln(ans1[l1],'.');
  write('If you want to order a pizza, you should call: ');
  for i:=1 to l2-1 do write(ans2[i],', ');
  writeln(ans2[l2],'.');
  write('If you want to go to a cafe with a wonderful girl, you should call: ');
  for i:=1 to l3-1 do write(ans3[i],', ');
  write(ans3[l3],'.');
  read(i);
end.