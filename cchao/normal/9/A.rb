a = gets.chomp.split.map(&:to_i).max
puts Rational(7 - a, 6)