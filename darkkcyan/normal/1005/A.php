<?php
$n = (int)fgets(STDIN);
$a = explode(' ', trim(fgets(STDIN)));
$ans = array();

for ($i = 0; $i < $n - 1; ++$i) {
    if ($a[$i + 1] === '1') {
        $ans[] = $a[$i];
    }
}
$ans[] = $a[$n - 1];

echo count($ans) . "\n";
foreach ($ans as $i) {
    print("$i ");
}