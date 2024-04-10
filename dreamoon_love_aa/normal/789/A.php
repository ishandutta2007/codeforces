<?php
list($n, $k) = explode(' ',fgets(STDIN));
$cnt=0;
$a = explode(' ',fgets(STDIN));
for($i = 0; $i < $n; $i++){
    $x=$a[$i];
    $cnt+=(int)floor(($x+$k-1)/$k);
}
echo (int)floor(($cnt+1)/2) . "\n";