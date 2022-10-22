var t, n, i, q, k, s:longint;
a:array[1..100] of longint;

BEGIN
  readln(t);
  
  for q:= 1 to t do
  begin
    readln(n);
    for i:= 1 to n do
      read(a[i]);
      
    k:= 0;
    s:= 0;
      
    for i:= 1 to n do
    begin
      if a[i] = 0 then
      begin
        k:= k + 1;
        s:= s + 1;
      end;
      
      s:= s + a[i];
    end;
    
    if(s = 0) then k:= k + 1;
    
    writeln(k);
  end;
END.