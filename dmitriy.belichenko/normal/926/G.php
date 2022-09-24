<?php 

$fl =STDIN; 
fgets($fl); 
$a = 0; 
$b = 0; 
$numbers = explode(" ", trim(fgets($fl))); 
foreach ($numbers as &$number) 
{ 
$number = intval($number); 
//printf("%d\n", $number); 
if ($number % 2 == 1) 
$a = $a + 1; 
else 
$b = $b + 1; 
} 
//printf("%d %d", $a, $b); 
if ($a >= $b) { 
printf("%d", $b + ($a - $b) / 3); 
} else { 
printf("%d", $a); 
} 
?>